#include "IDGenerator.h"

int id_generator::s_next_id_ = 1;
int id_generator::get_next_id()
{
	return s_next_id_++;
}
int id_generator::get_this_id()
{
	return s_next_id_;
}
