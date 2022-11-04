# everything is returned as an object
# can get methods / properties for everything
1 | Get-Member
dir | Get-Member

$files = dir

# returned object stored then first object in list queried
$files[0] | Get-Member

# call properties with . notation
$files[0].Name
