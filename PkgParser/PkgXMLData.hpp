 // PX2XMLData.hpp

#ifndef PX2XMLDATA_HPP
#define PX2XMLDATA_HPP

#include "PkgXMLNode.hpp"

namespace PkgParse
{

	class XMLData
	{
	public:
		XMLData ();
		~XMLData ();

		bool LoadFile (const std::string &fileName);
		bool LoadBuffer (const char *buffer, int size);
		bool SaveFile (const std::string &fileName);
		void Create ();

		XMLNode GetRootNode ();
		XMLNode NewChild (const std::string &name);

		// path="Config.RenderSystem.FXSetting",����м��κ�һ���ڵ㲻����,����
		// �սڵ�
		XMLNode GetNodeByPath (const char *path);

		void LinkEndChild (XMLNode node);

		XML_DOCPTR GetDoc()
		{
			return mDocument;
		}

	private:
		XMLData (const XMLData &);
		XMLData &operator= (const XMLData &);

		XML_DOCPTR mDocument;
		char *mDocStr;
	};

}

#endif