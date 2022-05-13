#include "Seat.h"

void Seat::set_id_name(string id, string name) {
	if (id == "" || name == "") {
		this->id = "";
		this->name = "";
	}
	this->id = id;
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