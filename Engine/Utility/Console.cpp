/*
 * Console.cpp
 * written by konlil
 *
 */

namespace Console
{
	//ofstream ConsoleFile;
	ofstream ConsoleFile("Console.txt");

	ofstream& File()
	{
		return ConsoleFile;
	}

	void WriteLine(const String &s)
	{
		HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD BytesWritten = 0;
		WriteConsole(stdHandle, s.CString(), s.Length(), &BytesWritten, NULL);
		WriteConsole(stdHandle, "\n", 1, &BytesWritten, NULL);
		ConsoleFile << s << endl;
		ConsoleFile.flush();
	}

	void WriteLine(const char *s)
	{
		HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD BytesWritten = 0;
		WriteConsole(stdHandle, s, strlen(s), &BytesWritten, NULL);
		WriteConsole(stdHandle, "\n", 1, &BytesWritten, NULL);
		ConsoleFile << s << endl;
		ConsoleFile.flush();
	}

	void WriteString(const String &s)
	{
		HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD BytesWritten = 0;
		WriteConsole(stdHandle, s.CString(), s.Length(), &BytesWritten, NULL);
		ConsoleFile << s;
		ConsoleFile.flush();
	}


	void WriteString(const char *s)
	{
		HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD BytesWritten = 0;
		WriteConsole(stdHandle, s, strlen(s), &BytesWritten, NULL);
		ConsoleFile << s;
		ConsoleFile.flush();
	}
}
