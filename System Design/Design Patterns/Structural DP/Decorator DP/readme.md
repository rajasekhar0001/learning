##### Problem Statement: Extending Functionality Without Modifying the Core Code ✨

Imagine you’re designing a coffee shop ordering system. The system needs to manage various coffee orders and their customizations. Customers can start with a basic coffee (e.g., Espresso, Cappuccino) and then add multiple customizations like milk, sugar, cream, or flavors (e.g., vanilla, hazelnut).

‍

**The Problem:**
Each coffee type and customization combination would require a new class if we follow a traditional inheritance-based approach. For example, you’d need separate classes for “EspressoWithMilk”, “CappuccinoWithVanilla”, or “LatteWithMilkAndSugar”. This quickly becomes unmanageable as the number of combinations grows.

‍

**The Challenge:**
How can you dynamically add new functionalities (customizations) to objects without altering their code or creating a complex class hierarchy?

‍
##### The Savior: Decorator Design Pattern 🦜
The Decorator Pattern is designed to address this problem by dynamically adding new functionalities to objects without modifying their code. It allows you to wrap objects in layers of functionality, creating flexible and extensible systems.

‍

**How the Decorator Pattern Works 🔧**
The Decorator Pattern achieves this by:

1. Defining a common interface for the base object and its decorators.

2. Using decorators to wrap base objects, adding new behaviors while preserving the original object’s interface.

3. Allowing multiple decorators to be stacked dynamically.