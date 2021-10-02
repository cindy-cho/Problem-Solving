def __init__ (self, policy=UP, state=STOPPED, floor=1):
    self.policy = policy
    self.state = state
    self.floor = floor

def copy(self, elevators):
    self.passengers = elevators["passengers"]
    self.state = elevators["status"]
    self.floor = elevators["floor"]