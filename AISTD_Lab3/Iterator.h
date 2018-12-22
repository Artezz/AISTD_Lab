#pragma once

class  Iterator {
public:
	virtual void next() = 0;
	virtual bool has_next() = 0;
	virtual int get_index() = 0;

};