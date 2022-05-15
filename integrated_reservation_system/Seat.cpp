#include "Seat.h"

void Seat::set_id(string id) {
	this->id = id;
}

void Seat::set_name(string name) {
	this->name = name;
}

void Seat::cancel() {
	this->id = "";
	this->name = "";
}

bool Seat::is_reserved() {
	return (id != "" && name != "");
}

pair<string, string> Seat::get_id_name() {
	return make_pair(id, name);
}