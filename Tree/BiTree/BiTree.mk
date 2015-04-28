##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BiTree
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Administrator\Desktop\Tree"
ProjectPath            := "C:\Users\Administrator\Desktop\Tree\BiTree"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=09/23/14
CodeLitePath           :="D:\CodeLite"
LinkerName             :=D:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=D:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="BiTree.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := D:/MinGW-4.8.1/bin/g++.exe 
CC       := D:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=D:\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/bitree.c$(ObjectSuffix) $(IntermediateDirectory)/queue.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Administrator/Desktop/Tree/BiTree/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/bitree.c$(ObjectSuffix): bitree.c $(IntermediateDirectory)/bitree.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Administrator/Desktop/Tree/BiTree/bitree.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bitree.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bitree.c$(DependSuffix): bitree.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bitree.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bitree.c$(DependSuffix) -MM "bitree.c"

$(IntermediateDirectory)/bitree.c$(PreprocessSuffix): bitree.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bitree.c$(PreprocessSuffix) "bitree.c"

$(IntermediateDirectory)/queue.c$(ObjectSuffix): queue.c $(IntermediateDirectory)/queue.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Administrator/Desktop/Tree/BiTree/queue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queue.c$(DependSuffix): queue.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queue.c$(ObjectSuffix) -MF$(IntermediateDirectory)/queue.c$(DependSuffix) -MM "queue.c"

$(IntermediateDirectory)/queue.c$(PreprocessSuffix): queue.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queue.c$(PreprocessSuffix) "queue.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/BiTree"


