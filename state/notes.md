# State

- fun with Finite State Machine

- a pattern in which the object's behavior is determined by its *state*
- an object transitions from one state to another (something needs to trigger the transition)
- a formalized construct which manages state and transitions is called **state machine**

### Motivation

- consider an ordinary telephone
- what you do with it depends on the state of the phone/line
    - if it's ringing or you want to make a call, you can pick it up
    - phone must be off the hook to talk/make the call
    - if you try calling someone and it's busy, you put the handset down
- changes in state can be explicit or in response to event (Observer pattern)


### Summary

- given sufficient complexity, it pays to formally define possible states and events/triggers
- can define:
    - state entry/exit behaviors
    - action when a particular event causes a transition
    - guard conditions enabling/disabling a transition
    - default action when no transitions are found for an event
