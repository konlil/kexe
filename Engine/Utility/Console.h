/*
 * Console.h
 * written by konlil
 *
 */

namespace Console
{
	ofstream& File();
	
	void WriteLine(const String &s);
	void WriteLine(const char *s);

	void WriteString(const String &s);
	void WriteString(const char *s);
}
