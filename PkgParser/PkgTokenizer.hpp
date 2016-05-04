// PkgTokenizer.hpp

#ifndef PKGTOKENIZER_HPP
#define PKGTOKENIZER_HPP

#include "PkgParsePre.hpp"

namespace PkgParse
{

	/// ���ַ������зָ�
	/**
	* TOK_IGNORE_EMPTY: �� tokens ������
	* TOK_TRIM:��β���ַ������ԣ�����
	*		StringTokenizer(",ab,cd,", ","); ��������token "ab"��"cd"
	*/
	class PkgStringTokenizer
	{
	public:
		enum Options
		{
			TOK_IGNORE_EMPTY = 1, /// ignore empty tokens
			TOK_TRIM = 2  /// remove leading and trailing whitespace from tokens
		};

		typedef std::vector<std::string>::const_iterator Iterator;

		PkgStringTokenizer(const std::string& str, const std::string& separators, int options = 0);
		~PkgStringTokenizer();

		Iterator Begin() const;
		Iterator End() const;

		const std::vector<std::string> &GetTokens() const;
		const std::string& operator [] (std::size_t index) const;
		std::size_t Count() const;
		/// Returns the number of tokens.

	private:
		PkgStringTokenizer(const PkgStringTokenizer&);
		PkgStringTokenizer& operator = (const PkgStringTokenizer&);

		std::vector<std::string> _tokens;
	};

}

#endif