# Omi Latency Lab
Composable tools for automated network application latency measurement and reporting.

As modern computing architectures have increased in complexity, latency and benchmarking have increasingly become more and more non-deterministic. Fortunately, networked application throughput can be measured scientifically by matching outbound response events to inbound trigger events.  Automated analysis can quickly find outliers and can be used to systematically tune the components of a trading platform.  Provided a standard packet capture, this latency lab provides components to quickly create custom tools for accurate benchmarking and verification.

# Example
Single run latency html report with javascript google chart:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/outputs/latency.html

The example data represents a series of outbound cme fix orders triggered by cme sbe market data packets. The spike at the beginning is due to core warming.

# Build
Use CMake...after specifying boost paths in CMakeLists.txt.

An easy to use example solution is provided for Visual Studio 15 in the windows directory. 

# Development
Please add regression tests for all omi file updates.  

# Disclaimer
All example input files are faked records modeled on tshark dissections. Any similaraity between existing people, places and/or protocols is purely incidental.

The Open Markets Initiative (Omi) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods. Enjoy.
