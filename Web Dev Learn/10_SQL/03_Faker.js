// This is used to generate fake data for us
const { faker } = require('@faker-js/faker');

createRandomUser = {
      userId: faker.string.uuid(),
      username: faker.internet.userName(),
      email: faker.internet.email(),
      avatar: faker.image.avatar(),
      password: faker.internet.password(),
      birthdate: faker.date.birthdate(),
      registeredAt: faker.date.past(),
    };

console.log(createRandomUser);