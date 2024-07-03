# Latency Lab

[![Test](https://github.com/Open-Markets-Initiative/latency-lab/actions/workflows/build.yml/badge.svg)](https://github.com/Open-Markets-Initiative/latency-lab/actions/workflows/build.yml)

Composable tools for automated networked application latency measurement.

External application throughput can be scientifically measured by matching
outbound responses to inbound trigger events.  Provided a standard 
packet capture, this latency lab provides templates to quickly create 
custom tools for accurate benchmarking, verification and system analysis.

## Examples

### [Latency Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/report/output/report.html)

The example data represents a series of outbound CME FIX orders triggered
by CME SBE market data packets. The spike at the beginning is due to core 
warming.

### [Comparison Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/comparison/output/comparison.html)

A comparison report allows for quickly comparing application response at 
multiple data speeds for stress testing. This example contains market data playback speeds of
1x, 2x, and 10x.

See [examples](https://github.com/Open-Markets-Initiative/latency-lab/tree/master/example "List of Example Latency Tools") directory for more use cases and build instructions.

## Open Markets Initiative

The Open Markets Initiative (Omi) is a group of technologists dedicated to 
enhancing the stability of electronic financial markets using modern 
development methods.

[Go to Omi Directory](https://github.com/Open-Markets-Initiative/Directory "Open Markets Initiative Repository Directory")

## Disclaimer

All example input data are faked records modeled on tshark dissections. 
Any similarities between existing people, places and/or protocols is purely 
incidental. 

Enjoy.
