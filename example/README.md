## Example Templates

### [Latency Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/report/output/report.html)

The example data represents a series of outbound CME fix orders triggered
by CME SBE market data packets. The spike at the beginning is due to core 
warming.

### [Latency Analysis](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/analysis/output/analysis.txt)

Latency statistics in text format.

### [Comparison Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/comparison/output/comparison.html)

A comparison report allows for quickly comparing application response to 
multiple different data speeds.

### [Latency Race](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/race/output/race.html)

A latency race will programtically determine the lowest latency of different build options.    

### [Event Matches](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/matching/output/matched.infos)

The example data represents a series of matched events.

Records format: 

```
frame number [Match Id] frame number
```

### [Emailable Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/email/output/email.html)

Email report uses only html (no javascript) for automated test emails per
run.

## Build

Use CMake. Visual studio projects are provided for rapid development. Some 
program templates contain a dependency on Boost 1.65.1.

## Directions

For now use examples to understand how to template a latency program, wiki will be up shortly. 