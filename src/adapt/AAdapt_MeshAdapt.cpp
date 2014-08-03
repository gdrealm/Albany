//*****************************************************************//
//    Albany 2.0:  Copyright 2012 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//

#include "AAdapt_MeshAdapt.hpp"
#include "AAdapt_MeshAdapt_Def.hpp"
#include <apfAlbany.h>

MESHADAPT_INSTANTIATE_TEMPLATE_CLASS(AAdapt::MeshAdaptE)
MESHADAPT_INSTANTIATE_TEMPLATE_CLASS(AAdapt::MeshAdaptT)

static double getAveragePartDensity(apf::Mesh* m)
{
  double nElements = m->count(m->getDimension());
  PCU_Add_Doubles(&nElements, 1);
  return nElements / PCU_Comm_Peers();
}

static int getShrinkFactor(apf::Mesh* m)
{
  double const minPartDensity = 1000;
  double partDensity = getAveragePartDensity(m);
  int factor = 1;
  while (partDensity < minPartDensity) {
    factor *= 2;
    partDensity *= 2;
    if (factor >= PCU_Comm_Peers())
      break;
  }
  assert(PCU_Comm_Peers() % factor == 0);
  return factor;
}

static void warnAboutShrinking(int factor)
{
  int nprocs = PCU_Comm_Peers() / factor;
  if (!PCU_Comm_Self())
    fprintf(stderr,"sensing mesh is spread too thin: adapting with %d procs\n",
        nprocs);
}

struct AdaptCallback* globalCallback;

static void theCallback(apf::Mesh2*)
{
  globalCallback->run();
}

void adaptShrunken(apf::Mesh2* m)
{
  int factor = getShrinkFactor(m);
  if (factor == 1)
    globalCallback->run();
  else {
    warnAboutShrinking(factor);
    alb::shrinkPartition(m, factor, theCallback);
  }
}
