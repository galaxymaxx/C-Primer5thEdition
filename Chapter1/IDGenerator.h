#pragma once

class id_generator
{
private:
	static int s_next_id_;

public:
	static int get_next_id();
	static int get_this_id();
};


