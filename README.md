# Omi Latency Lab
Composable tools for automated network application latency measurement and reporting.

External application throughput can be measured scientifically by matching outbound response events to inbound trigger events.  Automated analysis can quickly find outliers and can be used to systematically tune the components of a trading platform.  Provided a standard packet capture, this latency lab provides components to quickly create custom tools for accurate benchmarking and verification.

# Examples
#### Latency Report:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/report/output/report.html

The example data represents a series of outbound cme fix orders triggered by cme sbe market data packets. The spike at the beginning is due to core warming.

#### Latency Analysis:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/analysis/output/analysis.txt

Latency statistics in text format.

#### Event Matches:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/matching/output/matched.infos

The example data represents a series of matched events.  
Records format: 
    frame number [Match Id] frame number

#### Comparison Report:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/comparison/output/comparison.html

A comparison report allows for quickly comparing application response to multiple different data speeds.

#### Emailable Report:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/email/output/email.html

Email report uses only html (no javascript) for automated test emails per run.


# Build
Use CMake. Visual studio 2017 projects are provided for rapid development.  Some program templates contain a dependency on boost 1.64.  

# Disclaimer
The Open Markets Initiative (Omi) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods.

All example input data are faked records modeled on tshark dissections. Any similaraity between existing people, places and/or protocols is purely incidental. Enjoy.
