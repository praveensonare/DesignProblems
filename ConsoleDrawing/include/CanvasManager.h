#pragma once

#include <mutex>
#include <deque>

#include "ICanvas.h"
#include "MyUtils.h"

using namespace std;

class CanvasManager
{
public:
    static CanvasManager* GetInstance();
    void AddNewCanvas(ICanvas* p_Canvas);
    ICanvas* GetCanvasInFocus();

private:
    CanvasManager();
    ~CanvasManager() = default;
    CanvasManager(const CanvasManager&) = delete;
    CanvasManager& operator = (const CanvasManager&) = delete;

    static CanvasManager* m_Instance;
    static std::once_flag initInstanceFlag;

    deque<ICanvas*> m_CanvasList;
};
