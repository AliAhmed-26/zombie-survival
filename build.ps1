
$files = @(
    "main.cpp",
    "src/Game.cpp",
    "src/Player.cpp",
    "src/Person.cpp",
    "src/Map.cpp",
    "src/Weapon.cpp",
    "src/Ammo.cpp",
    "src/Bullet.cpp",
    "src/Enemy.cpp",
    "src/Zombie.cpp",
    "src/WeakZombie.cpp",
    "src/StrongZombie.cpp"
)

g++ $files -Iinclude -Iraylib/include -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -o game.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build successful!"
    Start-Process ".\game.exe"
}
else {
    Write-Host "Build failed!"
}
