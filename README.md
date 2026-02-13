# Seating Management System
This is a simple system that establishments such as restaurants or venues can use to manage seats, e.g, marking whether a seat/table is currently empty or occupied.<br/>

## Documentation
### Adding/Subtracting number of seats
When starting the program, there will be a pre-determined amount of empty grids (they represent the number of seats) displayed and keep in mind that you can not lessen this amount. However, if you find the initial number of grids few, you can simply add more seats by pressing the `+ Seats` button and the `- Seats` to perform the opposite. 
### Changing the seat status
By default, a grid will represent an empty space meaning that a seat doesn't exist on that area. <ins>To initialize a seat</ins>, simply right-click an empty grid.<br/>
Once a seat has been initialized the grid's color will change to `white` and its current state is neither empty or occupied. <ins>Left-clicking</ins> an initialized seat will change its color to `green`, meaning that it is currently empty. <ins>Left-clicking</ins> it for a second time will turn it `gray`, meaning that it is now occupied.<br/>

**For quick reference:**<br/>
`black` = empty space; seat doesn't exist on that area<br/>
`white` = a seat has been initialized on that area but is neither empty or occupied<br/>
`green` = currently empty<br/>
`gray` = currently occupied<br/>