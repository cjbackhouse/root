#ifndef ROOT_TGLVoxelPainter
#define ROOT_TGLVoxelPainter

#include <utility>
#include <vector>

#ifndef ROOT_TGLPlotPainter
#include "TGLPlotPainter.h"
#endif
#ifndef ROOT_TGLQuadric
#include "TGLQuadric.h"
#endif
#ifndef ROOT_TString
#include "TString.h"
#endif
#ifndef ROOT_TGLUtil
#include "TGLUtil.h"
#endif

class TGLOrthoCamera;
class TH1;
class TF1;

class TGLVoxelPainter : public TGLPlotPainter {
private:

   TString                 fPlotInfo;
   Rgl::Range_t            fMinMaxVal;

   TGLVoxelPainter(const TGLVoxelPainter &);
   TGLVoxelPainter &operator = (const TGLVoxelPainter &);

   mutable TGLLevelPalette fPalette;
   mutable std::vector<Double_t> fLevels;

public:
   TGLVoxelPainter(TH1 *hist, TGLPlotCamera *camera, TGLPlotCoordinates *coord);

   char   *GetPlotInfo(Int_t px, Int_t py);
   Bool_t  InitGeometry();
   void    StartPan(Int_t px, Int_t py);
   void    Pan(Int_t px, Int_t py);
   void    AddOption(const TString &stringOption);
   void    ProcessEvent(Int_t event, Int_t px, Int_t py);

private:
   //Overriders
   void    InitGL()const;
   void    DeInitGL()const;

   void    DrawPlot()const;


   void    DrawSectionXOZ()const;
   void    DrawSectionYOZ()const;
   void    DrawSectionXOY()const;

   void    DrawPalette()const;
   void    DrawPaletteAxis()const;

   //Aux. functions.
   void    FindVoxelColor(Double_t binContent, Float_t *rgba)const;
   void    SetVoxelColor(const Float_t *rgba)const;

   Bool_t  HasSections()const;
   void    PreparePalette()const;

   TF1    *fTransferFunc;

   ClassDef(TGLVoxelPainter, 0)//Voxel painter
};

#endif
