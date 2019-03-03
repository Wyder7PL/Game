#include "MUSGUICreate.h"

void MUSGUICreate::GenerateGUIButtons()
{
    Afterselecte = false;
    Markable::SetSelectedType(1);
    Markable::MarkedObjectInfo.changed = true;
    OIMBClickandDo * multi = new OIMBClickandDo(3,Position(200,30),Position(30,30),GUISkilltpyeButtonPoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);
    std::list <CTextureReferenceIllusion> TRI;
    {
        CTextureReferenceIllusion tri(Textures::textures->HoldOn);TRI.push_back(tri);
        CTextureReferenceIllusion tr2(Textures::textures->Canel);TRI.push_back(tr2);
        CTextureReferenceIllusion tr3(Textures::textures->Allow);TRI.push_back(tr3);
        CTextureReferenceIllusion tr4(Textures::textures->Enter);TRI.push_back(tr4);
    }
    multi = new OIMBClickandDo(4,Position(200,20),TRI,Position(40,40),GUICommonOrderButtonPoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);
    TRI.clear();
    CTextureReferenceIllusion tri(Textures::textures->DontIgnore);TRI.push_back(tri);
    CTextureReferenceIllusion tr2(Textures::textures->Ignore);TRI.push_back(tr2);
    multi = new OIMBClickandDo(2,Position(200,20),TRI,Position(40,40),GUIEnemyIgnorePoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);

}
