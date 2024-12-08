/**
 * @swagger
 * /login:
 *   get:
 *     summary: Entered to client
 *     tags: 
 *       - Login
 *     responses:
 *       200:
 *         description: User found
 *         content:
 *           application/json:
 *             schema:
 *               $ref: '#/components/schemas/user'
 *       404:
 *         description: User not found
 */
