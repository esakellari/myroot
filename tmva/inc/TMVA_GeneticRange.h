// @(#)root/tmva $Id: TMVA_GeneticRange.h,v 1.2 2006/05/08 20:56:16 brun Exp $    
// Author: Peter Speckmayer

/**********************************************************************************
 * Project: TMVA - a Root-integrated toolkit for multivariate data analysis       *
 * Package: TMVA                                                                  *
 * Class  : TMVA_GeneticRange                                                     *
 *                                                                                *
 * Description:                                                                   *
 *    Range definition for genetic algorithm                                      *
 *                                                                                *
 * Authors (alphabetical):                                                        *
 *      Peter Speckmayer <speckmay@mail.cern.ch>  - CERN, Switzerland             *
 *                                                                                *
 * Copyright (c) 2005:                                                            *
 *      CERN, Switzerland,                                                        * 
 *      U. of Victoria, Canada,                                                   * 
 *      MPI-KP Heidelberg, Germany                                                * 
 *      LAPP, Annecy, France                                                      *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in LICENSE           *
 * (http://mva.sourceforge.net/license.txt)                                       *
 *                                                                                *
 **********************************************************************************/

#ifndef ROOT_TMVA_GeneticRange
#define ROOT_TMVA_GeneticRange

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TMVA_GeneticRange                                                    //
//                                                                      //
// Range definition for genetic algorithm                               //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TRandom.h"

class TMVA_GeneticRange {

 public:

  TMVA_GeneticRange( TRandom *rnd, Double_t f, Double_t t );
  virtual ~TMVA_GeneticRange();

  Double_t fFrom, fTo;
  Double_t fTotalLength;

  TRandom *fRandomGenerator;

  Double_t Random( Bool_t near = kFALSE, Double_t value=0, Double_t spread=0.1, Bool_t mirror=kFALSE );

 private:

  // maps the values thrown outside of the ]from,to] interval back to the interval
  // the values which leave the range on the from-side, are mapped in to the to-side
  Double_t ReMap( Double_t val );

  // same as before, but the values leaving the allowed range, are mirrored into the range.
  Double_t ReMapMirror( Double_t val );
  ClassDef(TMVA_GeneticRange,0) //Range definition for genetic algorithm
};

#endif
