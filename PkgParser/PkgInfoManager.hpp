// PkgInfoManager.hpp

#ifndef PKGINFOMANAGER_HPP
#define PKGINFOMANAGER_HPP

#include "PkgClassInfo.hpp"
#include "PkgEnumInfo.hpp"
#include "PkgXMLNode.hpp"

namespace PkgParse
{

	class PkgInfoManager
	{
	public:
		static PkgInfoManager &GetSingleton();
		static PkgInfoManager *GetSingletonPtr();

		void Ternimate();

		void AddClassInfo(const std::string &name, PkgClassInfo *classInfo);
		PkgClassInfo *GetClassInfo(const std::string &className);

		void AddEnumInfo(const std::string &name, PkgEnumInfo *enumInfo);
		PkgEnumInfo *GetEnumInfo(const std::string &enumName);

		void CalInherit();

		bool Save(const std::string &filename);
		bool Load(const std::string &filename);

		bool GenToASFile();

	private:
		PkgInfoManager();
		~PkgInfoManager();

		void SaveParam(XMLNode &paramNode, ParamInfo *paramInfo);
		void SaveEnumInfo(XMLNode &parentNode, PkgEnumInfo *enumInfo);
		void GenASFileEnum(std::ofstream &out, PkgEnumInfo *enumInfo, int numTable);
		void GenASClassMemberFuns(std::ofstream &out, const std::string &className, 
			PkgClassInfo *classInfoLevel, int numTable, PkgClassInfo *classInfoTo);
		void GenASMemberFun(std::ofstream &out, const std::string &className, 
			const PkgFunInfo *funInfo, int numTable, PkgClassInfo *classInfoTo);
		void SetReference(PkgClassInfo *classInfo);

		static std::map<PkgFunInfo::FunType, std::string> sFunTypeStr;

		std::map<std::string, PkgClassInfo*> mClassInfoMap;
		std::vector<PkgClassInfo*> mClassInfos;

		std::map<std::string, PkgEnumInfo*> mEnumInfoMap;
		std::vector<PkgEnumInfo*> mEnumInfos;
	};

}

#endif