# Gabe DeHerrera 1 17 2025

import pygame
import random
pygame.init()
class Brick:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
        self.color = (random.randrange(100,250), random.randrange(100,250), random.randrange(100,250))
        self.isDead = False
    def draw(self):
        if not self.isDead:
            pygame.draw.rect(screen, self.color, (self.xpos, self.ypos, 125, 50))

    def collide(self, ballX, ballY):
        if not self.isDead:
            if(ballX + ballSize > self.xpos and 
               ballX < self.xpos + 125 and 
               ballY + ballSize > self.ypos and 
               ballY < self.ypos + 50):
                self.isDead = True
                return True 
            return False

#creates game screen and caption
screen = pygame.display.set_mode((800, 800), pygame.RESIZABLE)
pygame.display.set_caption("breakout")

gameover = False
clock = pygame.time.Clock()


PlayerX, PlayerY = 400, 700

ballX, ballY = 400, 400 
bVx, bYx = 5,5
ballSize = 5
score = 0

b1 = Brick(50,50)
b2 = Brick(200,50)
b3 = Brick(350,50)
b4 = Brick(500,50)
b5 = Brick(650,50)
b6 = Brick(50,150)
b7 = Brick(200,150)
b8 = Brick(350,150)
b9 = Brick(500,150)
b10 = Brick(650,150)

font = pygame.font.SysFont('calibri', 32)
text1 = font.render('score:', False, (0, 200, 200))
text2 = font.render(str(int(score)), 1, (0, 200, 200))

while not gameover:  # GAME LOOP
    ticks = clock.get_time()
    clock.tick(60)  # FPS
    gameEvents = pygame.event.get()
    # Input Section
    for event in gameEvents:  # quit game if x is pressed in top corner
        if event.type == pygame.QUIT:
            gameover = True
  
    keys = pygame.key.get_pressed()
    if keys[pygame.K_a]:
        PlayerX -= 10
    if keys[pygame.K_d]:
        PlayerX += 10

    ballY += bYx
    ballX += bVx 

    if ballX < 0 or ballX + ballSize > 800:
        bVx *= -1

    
    if ballY > PlayerY and ballX > PlayerX and ballX < PlayerX + 100:
        bYx *= -1
        bVx *= -1

     
    if b1.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b2.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b3.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b4.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b5.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b6.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b7.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b8.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b9.collide(ballX, ballY):
        bYx *= -1
        score += 1
    if b10.collide(ballX, ballY):
        bYx *= -1
        score += 1
    #render section
    screen.fill((0,0,0))


    pygame.draw.rect(screen, (255,255,255), (PlayerX, PlayerY, 100, 50))
    pygame.draw.circle(screen, (255,255,255), (ballX, ballY), ballSize) 

    b1.draw()
    b2.draw()
    b3.draw()
    b4.draw()
    b5.draw()
    b6.draw()
    b7.draw()
    b8.draw()
    b9.draw()
    b10.draw()

    text2 = font.render(str(int(score)), 1, (0, 200, 200))
    screen.blit(text1, (10, 10))
    screen.blit(text2, (110, 10))
    pygame.display.flip()

#END GAME LOOP
pygame.quit()
