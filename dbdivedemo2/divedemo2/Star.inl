inline Star& Star::move(IPoint aMovementDelta, ISize const & aModelSpaceSize)
{
  IASSERTSTATE (iDistanceIndex > 0);
  IPoint newPosition (iPosition + aMovementDelta / iDistanceIndex);
  if (newPosition.x() >= aModelSpaceSize.width())
  {
     newPosition.setX (newPosition.x() - aModelSpaceSize.width());
     newPosition.setY (rand() % aModelSpaceSize.height());
  }

  iPosition = newPosition;
  return *this;
}

inline Star& Star::draw(char* aBuffer, ISize const & aBufferSize,
  float xScale, float yScale)
{
  IPoint positionScaled (iPosition);
  positionScaled.scaleBy (xScale, yScale);
  ULONG const bufferOffset = positionScaled.y() * aBufferSize.width() +
     positionScaled.x();
  IASSERTSTATE (bufferOffset < aBufferSize.width() * aBufferSize.height());
  aBuffer [bufferOffset] = iDistanceIndex;
  return *this;
}

