#include "GUIResource.h"

GUIResource::GUIResource()
:Object(Position(0,0)),wood(Position(0,0)),stone(Position(80,0)),
iron(Position(0,0)),gold(Position(80,0)),
residens(Position(0,0)),maxresidens(Position(0,0))
{
    wood.SetTexture(Textures::textures->Wood);
    stone.SetTexture(Textures::textures->Stone);
    iron.SetTexture(Textures::textures->Iron);
    gold.SetTexture(Textures::textures->Gold);
    residens.SetTexture(Textures::textures->Occupants);
    maxresidens.SetTexture(Textures::textures->MaxOccupants);
}
GUIResource::~GUIResource(){}
void GUIResource::Step()
{
    wood.SetPosition(position.GetX(),position.GetY());
    wood.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(1)->GetAmount());
    wood.Step();
    stone.SetPosition(position.GetX()+80,position.GetY());
    stone.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(2)->GetAmount());
    stone.Step();
    iron.SetPosition(position.GetX(),position.GetY()+25);
    iron.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(3)->GetAmount());
    iron.Step();
    gold.SetPosition(position.GetX()+80,position.GetY()+25);
    gold.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(4)->GetAmount());
    gold.Step();
    residens.SetPosition(position.GetX(),position.GetY()+50);
    residens.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetResidents());
    residens.Step();
    maxresidens.SetPosition(position.GetX()+80,position.GetY()+50);
    maxresidens.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetMaxResidents());
    maxresidens.Step();
}
void GUIResource::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    wood.draw(target,states);
    stone.draw(target,states);
    iron.draw(target,states);
    gold.draw(target,states);
    residens.draw(target,states);
    maxresidens.draw(target,states);
}
void GUIResource::SetPlayerFraction(uint32_t * f)
{
    PlayerFraction = f;
}
