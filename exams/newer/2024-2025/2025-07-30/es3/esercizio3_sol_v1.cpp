#include <iostream>

// Port structure representing a network port
struct Port {
    int capacity;
    Port* next;
};

// Switch structure representing a network switch
struct Switch {
    int id;
    Port* ports;
    Switch* children;
    Switch* next;
};

// Recursive memory cleanup
void deletePorts(Port* port) {
    if (!port) return;
    deletePorts(port->next);
    delete port;
}

void deleteSwitches(Switch* sw) {
    if (!sw) return;
    deleteSwitches(sw->children);  // Delete child hierarchy
    deleteSwitches(sw->next);      // Delete sibling switches
    deletePorts(sw->ports);        // Delete associated ports
    delete sw;
}

// Add here below the declaration of the calculate function

int calculate(Switch* sw);

// Add here above the declaration of the calculate function

int main() {
    // Build sample network
    Switch* root = new Switch{1, nullptr, nullptr, nullptr};
    
    // Add ports to root
    root->ports = new Port{10, new Port{20, nullptr}};
    
    // Create child switches
    Switch* child1 = new Switch{2, nullptr, nullptr, nullptr};
    child1->ports = new Port{5, nullptr};
    
    Switch* child2 = new Switch{3, nullptr, nullptr, nullptr};
    child2->ports = new Port{2, new Port{3, nullptr}};
    
    Switch* grandchild = new Switch{4, nullptr, nullptr, nullptr};
    grandchild->ports = new Port{1, nullptr};
    
    // Connect hierarchy
    child2->children = grandchild;
    root->children = child1;
    child1->next = child2;  // Sibling relationship
    
    // Calculate and display total capacity
    std::cout << "Network Capacity: " 
              << calculate(root) << " Gbps\n";
    
    // Cleanup
    deleteSwitches(root);
    
    return 0;
}

// Add here below the definition of the calculate function

// Recursively sum port capacities in a linked list
int sumPorts(Port* port) {
    if (nullptr == port) return 0;
    return port->capacity + sumPorts(port->next);
}

// Recursively sum capacities of child switches
int sumChildSwitches(Switch* child) {
    if (nullptr == child) return 0;
    return calculate(child) + sumChildSwitches(child->next);
}

// Main recursive function to calculate total capacity
int calculate(Switch* sw) {
    if (nullptr == sw) return 0;
    return 3 * sumPorts(sw->ports) + 4 * sumChildSwitches(sw->children);
}
// Add here above the definition of the calculate function
