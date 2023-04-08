# Observer

- getting notifications when things happen
- **observer** - object that wishes to be informed about events happening in the system
- **observable** - entity generating the events

### Motivation

- we need to be informed when certain things happen
    - object's field changes
    - object does something
    - some external event occurs

- we want to listen to these events and notified when they occur
- terminology:
    - **event** and **subscriber**
    - **signal** and **slot** (boost, Qt, etc.)


### Summary

- two participants:
    - **observable** - provides a way of subscribing to an event (signal)
    - **observer** - performs the subscription

- **observable** implementation is always intrusive (observer doesn't need to be)

- multithreaded/reentrant use can cause issues

- ready-made implementations of Observer are available (e.g. boost)
