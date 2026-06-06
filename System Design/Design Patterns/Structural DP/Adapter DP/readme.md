**Problem Statement: *** Connecting the Unconnectable 🔌

Imagine you’re designing a smart home system. Your goal is to create a centralized app that controls various devices such as air conditioners, smart lights, coffee machines, and security cameras.

‍

Each device comes from a different manufacturer, and they all communicate differently:

• Air Conditioners use Bluetooth for communication.

• Smart Lights operate over Wi-Fi.

• Coffee Machines use Zigbee.

• Security Cameras rely on their own custom API.

‍

Now, your app needs to seamlessly control all these devices, regardless of the communication protocol.

‍

**The Problem: **** Each device uses a unique communication protocol, and your app would become a mess if you hard-code the logic for each device. It will be difficult to maintain and extend as more devices are added.

**The Challenge:** How can you create a clean, scalable solution to connect all these devices?