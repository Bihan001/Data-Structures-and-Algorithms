class Vehicle:
    tax = 0
    tires = 0
    ownership = ''
    vehicle_type = ''

    def __init__(self, tax, tires, ownership, vehicle_type):
        self.tax = tax
        self.tires = tires
        self.ownership = ownership
        self.vehicle_type = vehicle_type

    def set_ownership(self, name):
        self.ownership = name

    def __str__(self):
        return 'Class Vehicle - Tax: {}, Tires: {}, Ownership: {}, Vehicle Type: {}'.format(self.tax, self.tires, self.ownership, self.vehicle_type)


class Car(Vehicle):
    def __init__(self, ownership):
        super().__init__(1.3, 4, ownership, 'Private')

    def __str__(self):
        return 'Class Car - Tax: {}, Tires: {}, Ownership: {}, Vehicle Type: {}'.format(self.tax, self.tires, self.ownership, self.vehicle_type)

    def __add__(self, other):
        return self.tax + other.tax


v1 = Vehicle(1, 4, 'Bihan', 'Private')

car = Car('Naruto')

print(v1)
print(car)

print(Car.__add__(car, v1))

print(car + v1)

print(issubclass(Car, Vehicle))

print(isinstance(car, Vehicle))
