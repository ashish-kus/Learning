print("Helo World")
print("Helo World")
-- single line comment

local num = 99
NUMBER = 1

print(num, NUMBER)
local boolean = true
if boolean then
	print(boolean)
end

if boolean then
	print(boolean)
else
	print(NUMBER)
end

while boolean do
	print("nandu")
	boolean = false
end

-- tables

local t = { mykey = "nandu", "a", "b", { "x", "y", "z" } }
print(t[1])

-- Function
print("Functions")
local function print_table(table)
	for key, value in pairs(table) do
		print(key, value)
	end
end

print_table(t)
