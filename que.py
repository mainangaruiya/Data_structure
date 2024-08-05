class Queue:
    def __init__(self, max_size):
        # Initialize the queue with an empty list and set the maximum size
        self.queue = []
        self.max_size = max_size
    
    def is_empty(self):
        # Check if the queue is empty
        return len(self.queue) == 0
    
    def is_full(self):
        # Check if the queue is full
        return len(self.queue) == self.max_size
    
    def enqueue(self, name):
        # Add a name to the queue if it is not full
        if self.is_full():
            print("Queue is full")
        else:
            print(f"Queue before enqueue: {self.queue}")
            self.queue.append(name)
            print(f"Enqueued: {name}")
            print(f"Queue after enqueue: {self.queue}")
    
    def dequeue(self):
        # Remove and return the front name of the queue if it is not empty
        if self.is_empty():
            print("Queue is empty")
        else:
            print(f"Queue before dequeue: {self.queue}")
            name = self.queue.pop(0)
            print(f"Dequeued: {name}")
            print(f"Queue after dequeue: {self.queue}")
            return name
    
    def peek(self):
        # Return the front name of the queue without removing it
        if self.is_empty():
            print("Queue is empty")
        else:
            return self.queue[0]
    
    def display(self):
        # Display the current state of the queue
        if self.is_empty():
            print("Queue is empty")
        else:
            print(f"Queue: {self.queue}")

def display_commands():
    # Print the available commands for the user
    print("\nQueue Commands:")
    print("enqueue <name1> <name2> ... <nameN> - Add names to the queue")
    print("dequeue - Remove a name from the queue")
    print("peek - Show the front name of the queue")
    print("empty - Check if the queue is empty")
    print("full - Check if the queue is full")
    print("display - Display the queue")
    print("exit - Exit the program")

if __name__ == "__main__":
    # Main program execution
    max_size = int(input("Enter the maximum size of the queue: "))
    q = Queue(max_size)
    
    display_commands()
    
    while True:
        # Get the command from the user and process it
        command = input("\nEnter command: ").strip().lower()
        parts = command.split()
        
        if parts[0] == "enqueue" and len(parts) > 1:
            # Enqueue multiple names individually
            names = parts[1:]
            for name in names:
                q.enqueue(name)
        
        elif parts[0] == "dequeue":
            # Dequeue the front name
            q.dequeue()
        
        elif parts[0] == "peek":
            # Peek at the front name
            name = q.peek()
            if name is not None:
                print(f"Front name: {name}")
        
        elif parts[0] == "empty":
            # Check if the queue is empty
            if q.is_empty():
                print("Queue is empty")
            else:
                print("Queue is not empty")
        
        elif parts[0] == "full":
            # Check if the queue is full
            if q.is_full():
                print("Queue is full")
            else:
                print("Queue is not full")
        
        elif parts[0] == "display":
            # Display the current state of the queue
            q.display()
        
        elif parts[0] == "exit":
            # Exit the program
            print("Exiting...")
            break
        
        else:
            # Handle invalid commands
            print("Invalid command, please try again.")
            display_commands()
