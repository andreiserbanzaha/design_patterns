# Adapter Design pattern

- getting the interface you want from the interface you have
- a construct which adapts an existing interface X to conform to the required interface Y


### Summary

- implementing an adapter is easy
- determine the API you have and the API you need
- create components which aggregates (has reference to, ...) the adaptee
- intermediate representations can pile up, use caching and other optimizations
