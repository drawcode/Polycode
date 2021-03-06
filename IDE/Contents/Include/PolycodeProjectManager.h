/*
 Copyright (C) 2012 by Ivan Safrin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#include "Polycode.h"
#include "PolycodeGlobals.h"
#include "PolycodeProject.h"
#include "PolycodeProjectBrowser.h"

#pragma once 

using namespace Polycode;

class PolycodeProjectManager : public EventDispatcher {
	public:
		PolycodeProjectManager();
		~PolycodeProjectManager();
		
	void createNewFile(String templatePath, String newFileName);
	
	void createNewProject(String templateFolder, String projectName, String projectLocation);
	PolycodeProject* openProject(String path);
	void setProjectBrowser(PolycodeProjectBrowser *projectBrowser) { this->projectBrowser = projectBrowser; }
	
	PolycodeProject* getActiveProject() { return activeProject; }
	void setActiveProject(PolycodeProject* project);
	
	int getProjectCount() { return projects.size(); }
	PolycodeProject *getProjectByIndex(int index) { return projects[index]; }
	
	PolycodeProject *getProjectByProjectFile(String projectFile);
	
	void exportProject(PolycodeProject *project, String exportPath, bool macOS, bool windows, bool linux_);
	
	int removeProject(PolycodeProject *project);
	
	String activeFolder;
	String selectedFile;
	OSFileEntry selectedFileEntry;
	
protected:
	
	
	PolycodeProject* activeProject;
	
	PolycodeProjectBrowser *projectBrowser;
	vector<PolycodeProject*> projects;
	
};	
