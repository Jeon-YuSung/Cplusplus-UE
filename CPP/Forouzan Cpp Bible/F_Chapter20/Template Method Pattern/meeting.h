//템플릿 메소드 패턴 예제의 인터페이스 파일

#pragma once
#ifndef MEETING_H
#define MEETING_G
#include <iostream>
#include <string> 
#include <cassert>

using namespace std;

// Metting 부모 클래스의 인터페이스 
class Meeting {
	
public:
	void meeting();
	virtual void greeting() = 0;
	virtual void farewell() = 0;

};

//EnglishMeeting 자식 클래스의 인터페이스
class EngMeeting : public Meeting {
public:
	void greeting();
	void farewell();

};

//FrenchMeeting 자식 클래스의 인터페이스 
class FrenMeeting : public Meeting {

public:
	void greeting();
	void farewell();

};

#endif
