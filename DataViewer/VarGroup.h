/**
 * GeoDa TM, Copyright (C) 2011-2015 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 * 
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_VAR_GROUP_H__
#define __GEODA_CENTER_VAR_GROUP_H__

#include <list>
#include <map>
#include <vector>
#include <wx/string.h>

struct VarGroup;
typedef std::list<VarGroup> VarGroup_container;

struct VarGroup {
	VarGroup();
	VarGroup(const VarGroup& e);
	VarGroup(const wxString &name, int displayed_decimals=-1);
	VarGroup(const wxString &name, std::vector<wxString> vars,
			 int displayed_decimals=-1);

	bool operator<(const VarGroup& e) const;
	VarGroup& operator=(const VarGroup& e);
	void Append(const VarGroup& e);
	void AppendPlaceholder();
	bool IsAllPlaceholders() const;
	bool IsAnyPlaceholders() const;
	int GetNumTms() const;
    int GetNumVars() const;
	void GetVarNames(std::vector<wxString>& var_nms) const;
	wxString GetNameByTime(int time) const;
	wxString GetGroupName() const;
	/** renames the group */
	void SetGroupName(const wxString& new_name);
	/** rename simple var at given time */
	void SetVarName(const wxString& new_name, int time);
	bool IsSimple() const;
	bool IsEmpty() const;
	wxString ToStr() const;
	int GetDispDecs() const;
    int GetOGRPosition(int time) const;
	void SetDispDecs(int displayed_decimals);
    void AddMetaInfo(const wxString& key, const wxString& val);
    
	/** simple name if only one time period, otherwise group name */
	wxString name;

    // remember the position in ogr table, to prevent duplicate names
    unsigned int ogr_pos;

	/** var: empty "" indicates placeholder
	 * if vars.size() == 0, then a simple variable */
	std::vector<wxString> vars;

    // remember the position in ogr table, to prevent duplicate names
    std::vector<unsigned int> ogr_positions;

	/** Number of displayed decimals for the entire group.  Only
	 used for non-integer numeric types.  -1 indicates not used
	 or use default for type. */
	int displayed_decimals;

    // other for meta data:
    // <save category>
    // original name : aa
    // classification type : quantile
    // classification intervals : 1,2,3,4,5
    // <save selection>
    // original name : aa
    // selection range :
    // <save selection>
    // spatial selection :
    std::map<wxString, wxString> meta_data;
};

#endif
