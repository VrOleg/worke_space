/**
 * @swagger
 * /signup:
 *   post:
 *     summary: Creates a new user
 *     tags: 
 *       - Signup
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *              $ref: '#/components/schemas/user'
 *     responses:
 *       201:
 *         description: User created successfully
 *       400:
 *         description: Bad request
 */
