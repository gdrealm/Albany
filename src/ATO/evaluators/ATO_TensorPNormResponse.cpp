//*****************************************************************//
//    Albany 2.0:  Copyright 2012 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//

#include "PHAL_AlbanyTraits.hpp"

#include "ATO_TensorPNormResponse.hpp"
#include "ATO_TensorPNormResponse_Def.hpp"

template<typename EvalT, typename Traits>
const std::string ATO::TensorPNormResponse<EvalT, Traits>::className = "TensorPNormResponse";

PHAL_INSTANTIATE_TEMPLATE_CLASS(ATO::TensorPNormResponse)
