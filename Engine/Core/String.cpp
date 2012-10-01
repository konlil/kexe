/*
 * String.cpp
 * Written by konlil
 *
 * string class
 */

String& String::operator = (char ch)
{
	Allocate(4);
	_Length = 1;
	_Data[0] = ch;
	_Data[1] = '\0';
	return *this;
}

String& String::operator = (int i)
{
	ostringstream s(ostringstream::out);
	s << i;
	*this = s.str().c_str();	//str()返回string对象，c_str()返回char*
	return *this;
}

String& String::operator = (float f)
{
	ostringstream s(ostringstream::out);
	s << f;
	*this = s.str().c_str();
	return *this;
}

String& String::operator = (UINT u)
{
	ostringstream s(ostringstream::out);
	s << u;
	*this = s.str().c_str();
	return *this;
}

String& String::operator = (const char* s)
{
	UINT NewLength = UINT(strlen(s));
	Allocate(NewLength+1);
	memcpy(_Data, s, NewLength+1);
	_Length = NewLength;
	return *this;
}

String& String::operator = (const String &S)
{
	if(S._Length > 0)
	{
		const UINT startLength = _Length;
		ReSize(startLength + S._Length + 1);
		memcpy(_Data + startLength, S._Data, S._Length+1);
		_Length = startLength + S._Length;
	}
	return *this;
}

//string operations
String operator + (const String& l, const String& r)
{
	String result;
	const UINT length = l._Length + r._Length;
	result.Allocate(length + 1);
	result._Length = length;
	result._Data[length] = '\0';
	if(l._Length > 0)
		memcpy( result._Data, l._Data, l._Length);

	if(r._Length > 0)
		memcpy( result._Data + l._Length, r._Data, r._Length);

	return result;
}

ostream& operator << (ostream& o, const String& s)
{
	if(s.Length() > 0)
	{
		o.write(s.CString(), s.Length());
	}
	return o;
}