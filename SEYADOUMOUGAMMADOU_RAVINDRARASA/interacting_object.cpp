#include "interacting_object.h"


interacting_object::interacting_object()
    : _properties{ std::map<std::string, std::string>() }
{

}

interacting_object::~interacting_object() {

}

std::string interacting_object::getProprety(std::string key) {
    return _properties[key];
}

void interacting_object::setProprety(std::string key, std::string value) {
    this->_properties[key] = value;
}
void interacting_object::insertProprety(std::string key, std::string value) {
    this->_properties[key] = value;
}

// geteur pour obtenir l'attribut _properties 
std::map<std::string, std::string>& interacting_object::getProperties() {
    return _properties;
}
