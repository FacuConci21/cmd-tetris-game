#include "GameBackend.h"


void GameBackend::LoadSchemaData()
{
    std::ifstream ifsDataJSON("slots.json");

    ifsDataJSON >> jsonSlotSchema;

    ifsDataJSON.close();
}

void GameBackend::SaveSchemaData()
{
    std::ofstream ofsDataJSON("slots.json");

    ofsDataJSON << std::setw(4) << jsonSlotSchema;
    //ofsDataJSON << jsonSlotSchema;

    ofsDataJSON.close();
}

int GameBackend::SaveGame(json *ptrJsonMapMatrix)
{
    // instance of a JSON Slot type object.
	json jsonSlot;

    // loading schema data
    LoadSchemaData();

    // loading data on JSON Slot.
    jsonSlot["_id"] = (int) jsonSlotSchema["slots"].size();
    jsonSlot["playerName"] = slot.strPlayerName;
    jsonSlot["nCurrentShape"] = slot.nCurrentShape;
    jsonSlot["nPlayerScore"] = slot.nPlayerScore;
    jsonSlot["nMapMatrixState"] = *ptrJsonMapMatrix;

    jsonSlot["shapeState"]["ptTopLeft"]["x"] = slot.ptTopLeft.x;
    jsonSlot["shapeState"]["ptShapesStartingPoint"]["x"] = slot.ptShapesStartingPoint.x;
    jsonSlot["shapeState"]["ptShapesCurrentPoint"]["x"] = slot.ptShapesCurrentPoint.x;

    jsonSlot["shapeState"]["ptTopLeft"]["y"] = slot.ptTopLeft.y;
    jsonSlot["shapeState"]["ptShapesStartingPoint"]["y"] = slot.ptShapesStartingPoint.y;
    jsonSlot["shapeState"]["ptShapesCurrentPoint"]["y"] = slot.ptShapesCurrentPoint.y;

    jsonSlot["shapeState"]["sShapeLimits"]["width"] = slot.sShapeLimits.width;
    jsonSlot["shapeState"]["sShapeLimits"]["height"] = slot.sShapeLimits.height;

    // pushing back on JSON collection.
    jsonSlotSchema["slots"].push_back(jsonSlot);

    // saving data.
    SaveSchemaData();

    return 0;
}