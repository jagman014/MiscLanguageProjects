# get underlying command of alias
Get-Alias ls
Get-Alias dir

# set aliases for commands
Set-Alias blah Get-Process
blah

Get-Alias blah

# set alias to alias resolves to underlying command
Set-Alias blah dir
Get-Alias blah
