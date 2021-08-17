#include "CanvasManager.h"
#include "Canvas.h"

CanvasManager* CanvasManager::m_Instance = nullptr;
std::once_flag CanvasManager::initInstanceFlag;

CanvasManager* CanvasManager::GetInstance(){
  std::call_once(initInstanceFlag, [&](){
      m_Instance = new CanvasManager();
    });

  return m_Instance;
}

CanvasManager::CanvasManager()
{
    m_CanvasList.clear();
}

void CanvasManager::AddNewCanvas(ICanvas* p_Canvas)
{
    m_CanvasList.push_back(p_Canvas);
}

ICanvas* CanvasManager::GetCanvasInFocus()
{
    if (m_CanvasList.empty()) return nullptr;

    return m_CanvasList.back();
}
