# range lists generated like f#
Write-Output (1..10)

1..10 | ForEach-Object {$_ * 2}

1..10 | ForEach-Object {"This is loop number $_"}

1..10 | ForEach-Object {"*" * $_}

1..10 | ForEach-Object {if ($_ % 2) {"$_ is odd"}}
