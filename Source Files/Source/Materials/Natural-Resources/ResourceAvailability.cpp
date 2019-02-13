#include "ResourceAvailability.h"

ResourceAvailability::ResourceAvailability(uint32_t t):type(t){}

uint32_t ResourceAvailability::GetAmount(){return amoumt;}

uint32_t ResourceAvailability::GetType(){return type;}

void ResourceAvailability::SetAmount(uint32_t a){amoumt = a;}

void ResourceAvailability::SetType(uint32_t t){type = t;}

