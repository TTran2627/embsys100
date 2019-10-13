# **EMBEDDED DEVICE EXAMPLE**

Self-driving electric car a good example how embedded system work. Generally, this car will use GPS with live time traffic to figure out the best route to move between a starting point and destination. Also, this car will drive with zero passenger intervention by using multiple sensors, high speed optical cameras and machine learning. Power management is always a critical with any electric car, so the embedded system for this car need to optimize and balance between power usage, performance and safety.

**Development Challenges:**
1. *Throughput:*
   * Handing will a lot of data in a real time from multiple sensors.
2. *Response:*
   * Need to reacting almost real-time with zero latency with actuators to ensure safety when interact with live traffic and other vehicles.
   * This one becomes a top challenge right now to bring self-driving to real world
3. *Testability:*
   * Right now, just only testing with simulation model or on the street without traffic.
   * In fact, it is really hard to test driving control algorithm software with live traffic due to safety issue.
4. *Reliability:*
   * Almost no human intervention.
   * Need to implement redundancy controller or embedded software for duplication of critical function and maintain control all the time.
5. *Program Installation and upgrade:*
   * Special tools to install and upgrade the software at car dealership due to complex system.
   * Maybe in the future, the system can be self-update via wireless connectivity from anywhere.
6. *Power consumption:*
   * This car running on a bank of lithium battery, and software needs to help conserve power during trip.
   * Also, need implement recommendation system to re-route the car to possible electric station when low power for charging and avoid suddenly stop on the street.
7. *Security:*
   * Now security becomes the hot point for self-driving embedded system.
   * The system can lose control due to hacking via connectivity.
8. *Cost:*
   * Reducing the cost but still maintain performance features is usually a high priority for this system. 
