import FWCore.ParameterSet.Config as cms

from SHarper.HEEPAnalyzer.HEEPEventParameters_cfi import *

shNtupliser = cms.EDAnalyzer("SHNtupliser", heepEventPara,
    outputFilename = cms.string("testOutput.root"),
    datasetCode = cms.int32(0),
    sampleWeight = cms.double(1.),
    minEtToPromoteSC = cms.double(15.),
    addMet = cms.bool(True),
    addJets = cms.bool(True),
    addMuons = cms.bool(True),
    addTrigs = cms.bool(True),
    fillFromGsfEle = cms.bool(True),
    minEtToPassEvent = cms.double(-1.),
    outputGeom = cms.bool(True),                  
     # Isolation algos configuration
    intRadiusTk = cms.double(0.04), 
    ptMinTk = cms.double(0.7), 
    maxVtxDistTk = cms.double(0.2), 
    maxDrbTk = cms.double(999999999.), 
    intRadiusHcal = cms.double(0.15),
    etMinHcal = cms.double(0.0), 
    intRadiusEcalBarrel = cms.double(3.0), 
    intRadiusEcalEndcaps = cms.double(3.0), 
    jurassicWidth = cms.double(1.5), 
    etMinBarrel = cms.double(0.0),
    eMinBarrel = cms.double(0.08), 
    etMinEndcaps = cms.double(0.1), 
    eMinEndcaps = cms.double(0.0),  
    vetoClustered  = cms.bool(False),  
    useNumCrystals = cms.bool(True),
    # debug para
    hltDebugFiltersToSave = cms.vstring(),
    useHLTDebug = cms.bool(False)
     
                             
                           
                             
    
) 

