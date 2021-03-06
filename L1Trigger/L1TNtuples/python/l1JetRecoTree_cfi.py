import FWCore.ParameterSet.Config as cms

l1JetRecoTree = cms.EDAnalyzer("L1JetRecoTreeProducer",
  pfJetToken              = cms.untracked.InputTag("ak4PFJetsCHS"),
  jecToken                = cms.untracked.InputTag("ak4PFCHSL1FastL2L3ResidualCorrector"),
  maxJet                  = cms.uint32(20),
  jetptThreshold          = cms.double(10),
  pfMetToken              = cms.untracked.InputTag("pfMet")
)


