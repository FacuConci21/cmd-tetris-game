#include "GameBackend.h"

int GameBackend::SaveGame()
{
    // instance of a JSON Slot type object.
	json jsonSlot;

    // loading data on JSON Slot.
    jsonSlot["_id"] = slot.nId;
    jsonSlot["playerName"] = slot.strPlayerName;
    jsonSlot["nCurrentShape"] = slot.nCurrentShape;
    jsonSlot["nPlayerScore"] = slot.nPlayerScore;

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
    std::ofstream ofsDataJSON("slot0.json");

    ofsDataJSON << std::setw(4) << jsonSlotSchema;

    ofsDataJSON.close();

    return 0;
}