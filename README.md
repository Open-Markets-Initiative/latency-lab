# Omi Latency Lab
Composable tools for automated network application latency measurement and reporting.

As modern computing architectures have multiplied and increased in complexity, latency and benchmarking have become more and more non-deterministic...fortunately, networked throughput can be measured scientifically by matching inbound triggers to outbound responses.  Provided a standard packet capture, the Omi latency lab provides components to quickly create custom tools for accurate benchmarking.   

# Examples

Single run latency html report with javascript google chart:

https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/outputs/latency.html

The example data represents an inbound cme sbe market data packet triggering an outbound cme fix order. The spike at the beginning is due to core warming.  Since cpus are so complicated now this type of analysis is required for finding outliers and tuning the properties of a trading platform. The input files are faked records using tshark on Cme sbe version 8.1 and ilink fix.

# Build
Build instructions are in windows and linux directories, respectively. 

# Development
Please add regression tests for all omi file updates.  

# Disclaimer

The Open Markets Initiative (Omi) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods. Enjoy.
