/* String.h
 * written by konlil
 *
 * string class
 */

#pragma once

class String
{
public:
	String()
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
	}

	~String()
	{
		if(_Data != NULL)
		{
			delete[] _Data;
		}
	}

	String(const char* s)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = s;
	}

	String(char ch)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = ch;
	}

	//用explicit限制此类单参构造函数只能显示的调用，不能隐式转换
	explicit String(int n)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = n;
	}

	explicit String(float f)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = f;
	}

	explicit String(double f)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = float(f);
	}

	explicit String(UINT u)
	{
		_Data = NULL;
		_Capacity = 0;
		_Length = 0;
		*this = u;
	}

	String(const String &S)
	{
		if(S._Data == NULL)
		{
			_Data = NULL;
			_Capacity = 0;
			_Length = 0;
		}
		else
		{
			_Length = S._Length;
			const UINT newCapacity = _Length + 1;
			_Capacity = newCapacity;
			_Data = new char[newCapacity];
			memcpy(_Data, S._Data, newCapacity);
		}
	}

	//
	// Memory
	//
	
	__forceinline void FreeMemory()
	{
		if(_Data != NULL)
		{
			delete[] _Data;
			_Data = NULL;
		}
		_Length = 0;
		_Capacity = 0;
	}

	__forceinline void Allocate(UINT Capacity)
	{
		if(_Data != NULL)
		{
			delete[] _Data;
		}
		_Data = new char[Capacity];
		_Data[0] = '\0';
		_Length = 0;
		_Capacity = Capacity;
	}

	__forceinline void ReSize(UINT NewLength)
	{
		const UINT newCapacity = NewLength + 1;
		_Length = _Length < NewLength ? _Length : NewLength;
		char *newData = new char[newCapacity];
		if(_Length > 0)
		{
			memcpy(newData, _Data, _Length);
		}
		newData[_Length] = '\0';
		if(_Data != NULL)
		{
			delete[] _Data;
		}
		_Data = newData;
		_Capacity = newCapacity;
	}

	//
	// Accesors
	//
	__forceinline char* CString()
	{
		if(_Data != NULL)
		{
			return _Data;
		}
		else
		{
			return (char*)&(_Data);
		}
	}

	__forceinline const char* CString() const
	{
		if(_Data != NULL)
		{
			return _Data;
		}
		else
		{
			return (char*)&(_Data);
		}
	}

	__forceinline UINT Length() const
	{
		return _Length;
	}

	//
	// Assignment
	//
	String& operator = (const char* s);
	String& operator = (char ch);
	String& operator = (float f);
	String& operator = (int i);
	String& operator = (UINT u);
	String& operator = (const String &S);

private:
	friend String operator + ( const String& l, const String& r);

	char *_Data;
	UINT _Capacity;
	UINT _Length;
};

//string operations
String operator + ( const String& l, const String& r);
ostream& operator << ( ostream& o, const String& s);
